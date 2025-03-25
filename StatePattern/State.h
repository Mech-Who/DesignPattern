#pragma once
#ifndef __STATE_H__
#define __STATE_H__

struct Document;

struct State {
	virtual ~State() = default;
	virtual void Render() = 0;
	virtual void Publish() = 0;
	inline void SetDoc(Document* d) { doc = d; }
protected:
	Document* doc = nullptr;
};

struct Draft: public State {
	void Render() override;
	void Publish() override;
};

struct Moderation: public State {
	void Render() override;
	void Publish() override;
};

struct Published: public State {
	void Render() override;
	void Publish() override;
};

struct Document {
	Document();
	~Document();
	void Render();
	void Publish();
	void ChangeState(State* state);
private:
	State* state;
};

#endif // __STATE_H__
