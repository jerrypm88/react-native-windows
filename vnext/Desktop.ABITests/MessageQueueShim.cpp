#include "MessageQueueShim.h"

#include <IntegrationTests/ControllableMessageQueueThread.h>

namespace ABITests {
MessageQueueShim::MessageQueueShim()
    : m_messageQueueThread{std::make_shared<Microsoft::React::Test::ControllableMessageQueueThread>()} {}

MessageQueueShim::MessageQueueShim(std::shared_ptr<::facebook::react::MessageQueueThread> messageQueueThread)
    : m_messageQueueThread{std::move(messageQueueThread)} {}

void MessageQueueShim::Run(::winrt::facebook::react::QueueItem const &item) const {
  m_messageQueueThread->runOnQueue(item);
}

void MessageQueueShim::RunSync(::winrt::facebook::react::QueueItem const &item) const {
  m_messageQueueThread->runOnQueueSync(item);
}

void MessageQueueShim::QuitSync() const {
  m_messageQueueThread->quitSynchronous();
}
} // namespace ABITests
