#pragma once

#include "IThreadable.h"
#include "../lesson.03.cpp/IExecuteable.h"

class QueueCommand : public IExecuteable
{
protected:
	IThreadable::Ptr m_threadable;
	IExecuteable::Ptr m_command;

public:

	QueueCommand(IThreadable::Ptr threadable, IExecuteable::Ptr command) : m_threadable(threadable), m_command(command) {}

	void Execute() override {
		ExecuteableQueue::Ptr queue = m_threadable->GetQueue();
		queue->Put(m_command);
	}
};
