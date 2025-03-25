#pragma once
#ifndef __TEMPLATE_METHOD_H__
#define __TEMPLATE_METHOD_H__


struct AbstractMethod
{
    virtual ~AbstractMethod() = default;
    // ģ�巽��
    void TemplateMethod() const;
    // ����ֱ��ʵ�ֵķ���
protected:
    void BaseOperation1() const;
    void BaseOperation2() const;
    void BaseOperation3() const;
    // ������Ҫʵ�ֵķ���
    virtual void RequiredOperations1() const = 0;
    virtual void RequiredOperation2() const = 0;
    // hook ��Ϊ��չ��
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
