#pragma once
#include <iostream>
#include <functional>
#include <map>
#include <thread>
#include <mutex>
#include "IWriteOnlyChannel.hpp"

namespace cm {
    class WriteOnlyChannel: public virtual IWriteOnlyChannel {
        public:
            bool sendMessage(const std::string& msg) final;
            bool sendData(const char* data, size_t lenght) final;

            virtual bool sendMessageImpl(const std::string& msg) = 0;
            virtual bool sendDataImpl(const char* data, size_t lenght) = 0;

            virtual ~WriteOnlyChannel() {}
        private:
            std::mutex guard;
    };
}