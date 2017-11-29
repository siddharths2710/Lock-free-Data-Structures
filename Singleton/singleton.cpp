#include <iostream>
#include <mutex>
#include "singleton.h"

// Singleton* Singleton::inst;
// std::mutex Singleton::mutex_inst;

Singleton::Singleton() {}

// Singleton* Singleton::getInstance() {
// 	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
// 	std::atomic_thread_fence(std::memory_order_acquire);
// 	if (tmp == nullptr) {
// 		std::lock_guard<std::mutex> lock(mutex_inst);
// 		tmp = m_instance.load(std::memory_order_relaxed);
// 		if (tmp == nullptr) {
// 			tmp = new Singleton;
// 			std::atomic_thread_fence(std::memory_order_release);
// 			m_instance.store(tmp, std::memory_order_relaxed);
// 		}
// 	}
// 	return tmp;
// }

std::atomic<Singleton*> Singleton::m_instance;

Singleton* Singleton::getInstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	// std::atomic_thread_fence(std::memory_order_acquire);
	if (tmp == nullptr) {
		std::cout << "Inside\n";// << std::endl;
		tmp = new Singleton;
		Singleton* val = nullptr;
		if (m_instance.compare_exchange_strong(val, tmp, std::memory_order_relaxed)) {
			tmp = m_instance.load(std::memory_order_relaxed);
			std::cout << "Inside Inside" << std::endl;
		}
	}
	return tmp;
}

// Singleton* Singleton::getInstance() {
// 	if (!inst) {
// 		std::lock_guard<std::mutex> guard(mutex_inst);
// 		if (!inst) {
// 			inst = new Singleton();
// 		}
// 	}
// 	return inst;
// }
