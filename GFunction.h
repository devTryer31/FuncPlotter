#pragma once

#include <string>
#include <regex>
#include <sstream>
#include <queue>

//================================Nodes classes================================//

class Node {
	public: virtual double Evaluate() const = 0;
};

/// <summary>
/// Used to get a simple number in the expression.
/// </summary>
class NumberNode final : public Node {
public:
	NumberNode(double number);
	double Evaluate() const override;
private:
	const double Number;
};

/// <summary>
/// Used to get a variable in the expression.
/// </summary>
class VariableNode final : public Node {
public:
	VariableNode(double x);
	double Evaluate() const override;
private:
	const double X;
};

class OperationNode final: public Node {
public:
	OperationNode(char op);

	double Evaluate() const override;
	uint8_t GetPriority() const;

	void SetLeftOperand(std::shared_ptr<const Node> left);

	void SetRightOperand(std::shared_ptr<const Node> right);

private:
	const char Operation;
	const uint8_t Priority;
	std::shared_ptr<const Node> Left, Right;
};



//================================Func class================================//

/// <summary>
/// Class of a mathematical function.
/// </summary>
class Func {
public:
	/// <summary>
	/// Sets the function definition.
	/// </summary>
	Func(std::string expression);
	double EvaluateInPoint(double variable) const;
	/// <summary>
	/// Function definition.
	/// </summary>
	std::string GetExpression() const;
private:
	double Evaluate(std::string::const_iterator& begin, std::string::const_iterator end, double veriable) const;
	std::string Expression;
};

