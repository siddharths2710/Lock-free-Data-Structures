#ifndef SINGLE_H
#define SINGLE_H

#include <mutex>
#include <atomic>

class Singleton {
	// static Singleton* inst;
	static std::atomic<Singleton*> m_instance;
	// static std::mutex mutex_inst;
	Singleton();
public:
	static Singleton* getInstance();
	std::string name;
};

#endif
