#ifndef __EXPR_HPP___
#define __EXPR_HPP___
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>

class Expression {
 public:
  Expression() {}
  virtual std::string toString() const = 0;
  virtual ~Expression() {}
  virtual long evaluate() const = 0;
};

class NumExpression : public Expression {
  long num;

 public:
  NumExpression(long n) : num(n) {}
  virtual std::string toString() const {
    std::ostringstream ans;
    ans << num;
    return ans.str();
  }
  virtual long evaluate() const { return num; }
  virtual ~NumExpression() {}
};

class PlusExpression : public Expression {
  Expression * l;
  Expression * r;

 public:
  PlusExpression(Expression * lhs, Expression * rhs) : l(lhs), r(rhs) {}
  virtual std::string toString() const {
    return "(" + l->toString() + " + " + r->toString() + ")";
  }
  virtual long evaluate() const { return l->evaluate() + r->evaluate(); }
  virtual ~PlusExpression() {
    delete l;
    delete r;
  }
};

class MinusExpression : public Expression {
  Expression * l;
  Expression * r;

 public:
  MinusExpression(Expression * lhs, Expression * rhs) : l(lhs), r(rhs) {}
  virtual std::string toString() const {
    return "(" + l->toString() + " - " + r->toString() + ")";
  }
  virtual long evaluate() const { return l->evaluate() - r->evaluate(); }
  virtual ~MinusExpression() {
    delete l;
    delete r;
  }
};

class TimesExpression : public Expression {
  Expression * l;
  Expression * r;

 public:
  TimesExpression(Expression * lhs, Expression * rhs) : l(lhs), r(rhs) {}
  virtual std::string toString() const {
    return "(" + l->toString() + " * " + r->toString() + ")";
  }
  virtual long evaluate() const { return l->evaluate() * r->evaluate(); }
  virtual ~TimesExpression() {
    delete l;
    delete r;
  }
};

class DivExpression : public Expression {
  Expression * l;
  Expression * r;

 public:
  DivExpression(Expression * lhs, Expression * rhs) : l(lhs), r(rhs) {}
  virtual std::string toString() const {
    return "(" + l->toString() + " / " + r->toString() + ")";
  }
  virtual long evaluate() const { return l->evaluate() / r->evaluate(); }
  virtual ~DivExpression() {
    delete l;
    delete r;
  }
};

#endif
