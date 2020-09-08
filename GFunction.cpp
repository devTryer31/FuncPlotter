#include "GFunction.h"

//================================Nodes classes================================//

NumberNode::NumberNode(double number) : Number(number) {};

double NumberNode::Evaluate() const{
	return Number;
}

//====

VariableNode::VariableNode(double x) : X(x) {};

double VariableNode::Evaluate() const{
	return X;
}

//===

OperationNode::OperationNode(char op) :
	Operation(op),
	Priority(
		[op] {
			if (op == '*' || op == '/') return 1u;
			else return 0u;
		}()
			)
{};

double OperationNode::Evaluate() const {
	if (Operation == '*') {
		return Left->Evaluate() * Right->Evaluate();
	}
	else if (Operation == '-') {
		return Left->Evaluate() - Right->Evaluate();
	}
	else if (Operation == '+') {
		return Left->Evaluate() + Right->Evaluate();
	}
	else if (Operation == '/') {
		double REval = Right->Evaluate();
		if (REval != 0) {
			return Left->Evaluate() / REval;
		}
		else throw std::invalid_argument("Division by zero.");
	}
	else throw std::invalid_argument("Unknown operation: " + std::to_string(Operation));
}

uint8_t OperationNode::GetPriority() const {
	return Priority;
}

void OperationNode::SetLeftOperand(std::shared_ptr<const Node> left) {
	Left = left;
}

void OperationNode::SetRightOperand(std::shared_ptr<const Node> right) {
	Right = right;
}

//================================Func class================================//

Func::Func(std::string expression) {
	expression.erase(std::remove_if(expression.begin(), expression.end(), [](char ch) {
														return (ch == ' ' || ch == '\t'); }), expression.end());
	std::regex regular(
		"(\\(*\\-?x\\)*|\\(*\\-?\\d+\\.?[0-9]*\\)*)([\\+|\\-|\\*|\\/*](\\(*\\-?x\\)*|\\(*\\-?\\d+\\.?[0-9]*\\)*))*"
	);
	//If the expression is correct in characters, but maybe not in math.
	if (std::regex_match(expression.begin(), expression.end(), regular)) {
		int balance = 0;
		//Ñhecking the bracket order.
		for (uint32_t i = 0; i < expression.size(); ++i) {
			if (expression[i] == '(') {
				balance++;
			}
			else if (expression[i] == ')') {
				if (--balance < 0) {
					throw std::invalid_argument("Invalid expression (unexpected symbol ')'): " + expression + ".");
				}				
			}
		}
		if (balance == 0) {//The expression is correct.
			Expression = expression;
		}
		else {
			throw std::invalid_argument("Invalid expression (unexpected symbol '('): " + expression+".");
		}
	}
	else {
		throw std::invalid_argument("Invalid expression: " + expression + ".");
	}
}

std::string Func::GetExpression() const {
	return Expression;
}


double Func::EvaluateInPoint(double variable) const {
	std::string::const_iterator begin = Expression.cbegin(), end = Expression.cend();
	if (begin == end) {
		throw std::invalid_argument("Empty expression.");
	}
	return Evaluate(begin, end, variable);
}

double Func::Evaluate(std::string::const_iterator& begin, std::string::const_iterator end, double variable)const {
	std::deque<std::shared_ptr<OperationNode>> operations;
	std::deque<std::shared_ptr<Node>> operands;
	std::string::const_iterator it;

	auto CheckPriorityOperationLocal = [&](double Number) {
		if (!operations.empty() && operations.back()->GetPriority() >= 1) {
			std::shared_ptr<OperationNode> topOp = operations.back();
			topOp->SetLeftOperand(operands.back()); operands.pop_back();
			topOp->SetRightOperand(std::make_shared<NumberNode>(Number));
			operands.push_back(std::make_shared<NumberNode>(topOp->Evaluate()));
			operations.pop_back();
		}
		else
			operands.push_back(std::make_shared<NumberNode>(Number));
	};

	for (it = begin; it != end && *it != ')'; std::advance(it, 1)) {
		if (*it == '(') {
			std::advance(it, 1);
			CheckPriorityOperationLocal(Evaluate(it, end, variable));
		}

		if (*it == '+' || *it == '*' || *it == '/' ||
			(*it == '-' && it != begin && (isdigit(*std::prev(it)) || *std::prev(it) == 'x'|| *std::prev(it) == ')')))
		{
			if (operands.empty()) throw std::logic_error("Operand not found.");
			operations.push_back(std::make_shared<OperationNode>(*it));
		}
		else if (isdigit(*it) || (*it == '-' && isdigit(*std::next(it)))) {
			std::stringstream ss;
			ss << *it;
			std::advance(it, 1);
			uint8_t point_cnt = 0;
			while (it != end && *it != ')' && (isdigit(*it) || *it == '.')) {
				if (*it == '.')
					point_cnt++;
				if (point_cnt == 2)
					throw std::invalid_argument("Invalid double operand (second point ('.') founded).");
				ss << *it;
				std::advance(it, 1);
			}
			double num;
			ss >> num;
			std::advance(it, -1);
			CheckPriorityOperationLocal(num);
		}
		else if (*it == 'x' || (*it == '-' && 'x' == *std::next(it))) {
			std::shared_ptr<VariableNode> XKeeper;
			if (*it == '-') {
				std::advance(it, 1);
				XKeeper = std::make_shared<VariableNode>(-variable);
			}
			else {
				XKeeper = std::make_shared<VariableNode>(variable);
			}
			if (!operations.empty() && operations.back()->GetPriority() >= 1) {
				std::shared_ptr<OperationNode> topOp = operations.back();
				topOp->SetLeftOperand(operands.back()); operands.pop_back();
				topOp->SetRightOperand(XKeeper);
				operands.push_back(std::make_shared<NumberNode>(topOp->Evaluate()));
				operations.pop_back();
			}
			else
				operands.push_back(XKeeper);
		}
		else if (*it != ')') throw std::invalid_argument("Invalid token: " + std::to_string(*it));
	}
	begin = it;
	while (!operations.empty()) {
		std::shared_ptr<OperationNode> topOp = operations.front();
		topOp->SetLeftOperand(operands.front()); operands.pop_front();
		topOp->SetRightOperand(operands.front()); operands.pop_front();
		operands.push_front(std::make_shared<NumberNode>(topOp->Evaluate()));
		operations.pop_front();
	}
	if (operations.empty()) {
		return operands.back()->Evaluate();
	}
	else throw std::logic_error("Operand not found.");
}