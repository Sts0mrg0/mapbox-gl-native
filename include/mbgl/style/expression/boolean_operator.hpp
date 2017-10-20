#pragma once
#include <mbgl/style/expression/expression.hpp>

namespace mbgl {
namespace style {
namespace expression {

class Any : public Expression  {
public:
    Any(std::vector<std::unique_ptr<Expression>> inputs_) :
        Expression(type::Boolean),
        inputs(std::move(inputs_))
    {}

    static ParseResult parse(const mbgl::style::conversion::Convertible& value, ParsingContext ctx);

    EvaluationResult evaluate(const EvaluationParameters& params) const override;
    void eachChild(std::function<void(const Expression*)> visit) const override;

private:
    std::vector<std::unique_ptr<Expression>> inputs;
};

class All : public Expression  {
public:
    All(std::vector<std::unique_ptr<Expression>> inputs_) :
        Expression(type::Boolean),
        inputs(std::move(inputs_))
    {}

    static ParseResult parse(const mbgl::style::conversion::Convertible& value, ParsingContext ctx);

    EvaluationResult evaluate(const EvaluationParameters& params) const override;
    void eachChild(std::function<void(const Expression*)> visit) const override;

private:
    std::vector<std::unique_ptr<Expression>> inputs;
};

} // namespace expression
} // namespace style
} // namespace mbgl

