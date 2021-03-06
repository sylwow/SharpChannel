#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <map>
#include <thread>
#include <mutex>
#include "Channels/IWriteOnlyChannel.hpp"

namespace cm
{
    class WriteOnlyChannel : public virtual IWriteOnlyChannel
    {
    public:
        using Ptr = std::shared_ptr<WriteOnlyChannel>;

        bool next(const std::string &msg) final;
        bool next(const std::vector<char> &data) final;

    protected:
        virtual bool sendMessageImpl(const std::string &msg) = 0;
        virtual bool sendDataImpl(const std::vector<char> &data) = 0;
   
    private:
        std::mutex _guard;
    };
}