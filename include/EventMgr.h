#ifndef EVENT_MGR_H
#define EVENT_MGR_H

/**
 * @todo: sooooo many tweaks left to do here.
 * 1. payload and eventId on callbacks (handlers)
 * 2. enum for eventIds
 */

#include <functional>
#include <unordered_map>
#include <vector>

using std::function;
using std::unordered_map;
using std::vector;

using Subscriber = function<void()>;
using Subscription = vector<Subscriber>::iterator;

unordered_map<int, vector<Subscriber>> _event_mgr_subscriptions;

class EventMgr
{
public:

  static Subscription subscribe(int eventType, Subscriber eventHandler)
  {
    _event_mgr_subscriptions[eventType].push_back(eventHandler);
    return std::prev(_event_mgr_subscriptions[eventType].end());
  }

  static void unsubscribe(int eventType, Subscription subscription)
  {
    _event_mgr_subscriptions[eventType].erase(subscription);
  }

  static void publish(int eventType)
  {
    for (const auto &callback : _event_mgr_subscriptions[eventType])
    {
      callback();
    }
  }
};

#endif
