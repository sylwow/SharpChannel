#pragma once
#include <iostream>
#include <functional>
#include <map>
#include <mutex>
#include "Channels/IReadOnlyChannel.hpp"
#include "Channels/IChannelEventLoop.hpp"
#include "Channels/CallbacksMap.hpp"

namespace cm
{
    class ReadOnlyChannel : public IReadOnlyChannel
    {
    public:
        using Ptr = std::unique_ptr<ReadOnlyChannel>;

        std::unique_ptr<IUnsubscribable> subscribe(const OnMessageReceived &onMessageReceived) final;
        std::unique_ptr<IUnsubscribable> subscribe(const OnDataReceived &onDataReceived) final;
        std::unique_ptr<IUnsubscribable> subscribe(const OnCompleted &onCompleted) final;
        std::unique_ptr<IUnsubscribable> subscribe(const OnError &onError) final;

        std::unique_ptr<IUnsubscribable> subscribe(const OnCompleted &onCompleted, const OnError &onError) final;

        std::unique_ptr<IUnsubscribable> subscribe(const OnMessageReceived &onMessageReceived, const OnCompleted &onCompleted, const OnError &onError) final;
        std::unique_ptr<IUnsubscribable> subscribe(const OnDataReceived &onDataReceived, const OnCompleted &OnCompleted, const OnError &onError) final;

        std::unique_ptr<IUnsubscribable> subscribe(IDataObserver &observer) final;
        std::unique_ptr<IUnsubscribable> subscribe(IErrorObserver &observer) final;
        std::unique_ptr<IUnsubscribable> subscribe(ICompleteObserver &observer) final;
        std::unique_ptr<IUnsubscribable> subscribe(IMessageObserver &observer) final;

        std::unique_ptr<IUnsubscribable> subscribe(IChannelDataObserver &observer) final;
        std::unique_ptr<IUnsubscribable> subscribe(IChannelMessageObserver &observer) final;

        void setChannelEventLoop(IChannelEventLoop *eventLoop);
        ~ReadOnlyChannel() {}

    protected:
        void completeAll();
        void nextAll(const std::string &msg);
        void nextAll(const std::vector<char> &data);
        void errorAll(const std::exception &error);

    private:
        std::shared_ptr<CallbacksMap> _callbacksMap = std::make_shared<CallbacksMap>();
        IChannelEventLoop *_eventLoop = nullptr;
    };
}