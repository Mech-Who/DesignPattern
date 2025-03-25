#pragma once
#ifndef __TEMPLATE_METHOD_H__
#define __TEMPLATE_METHOD_H__


struct AbstractMethod
{
    virtual ~AbstractMethod() = default;
    // 模板方法
    void TemplateMethod() const;
    // 基类直接实现的方法
protected:
    void BaseOperation1() const;
    void BaseOperation2() const;
    void BaseOperation3() const;
    // 子类需要实现的方法
    virtual void RequiredOperations1() const = 0;
    virtual void RequiredOperation2() const = 0;
    // hook 作为拓展点
    virtual void Hook1() const;
    virtual void Hook2() const;
};

struct ConcreteMethodA: public AbstractMethod
{
protected:
    void RequiredOperations1() const override;
    void RequiredOperation2() const override;
};

struct ConcreteMethodB: public AbstractMethod
{
protected:
	void RequiredOperations1() const override;
	void RequiredOperation2() const override;
    void Hook1() const override;
};

#endif	// __TEMPLATE_METHOD_H__
