#pragma once
#include "IObservers.hpp"

namespace cm
{
    struct IWriteOnlyChannel : public ICompleteObserver, public IErrorObserver, public IMessageObserver, public IDataObserver
    {
        using Ptr = std::unique_ptr<IWriteOnlyChannel>;

        ~IChannelObserver() {}
    };
}