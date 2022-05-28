/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
#include <queue>
#include <iostream>

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Construct array a, where a[i] represents how many
        // times task i is expected to be scheduled
        int a[26] = { 0 };
        for(int task: tasks)
        {
            a[task - 'A']++;
        }

        // Construct priority queue with entries representing
        // number of times a given task is expected to be scheduled
        std::priority_queue<int> prio_q;
        for(int task: a)
        {
            if(task != 0)
            {
                prio_q.push(task);
            }
        }

        // Initialize empty cooldown queue, where entries are pairs <int, int>,
        // where first integer represents remaining schedule count and second integer
        // represents a timestamp at which previous instance of this task was
        // scheduled
        std::queue<std::pair<int, int>> cooldown_q;
        int clock;
        for(clock = 0; prio_q.size() != 0 || cooldown_q.size() != 0; clock++)
        {
            // Check cooldown queue
            if(cooldown_q.size() != 0)
            {
                const std::pair<int, int>& cooled_down = cooldown_q.front();
                if(clock - cooled_down.second == 0)
                {
                    prio_q.push(cooled_down.first);
                    cooldown_q.pop();
                }
            }

            // Schedule next task
            if(prio_q.size() != 0)
            {
                int top = prio_q.top();
                top--;
                if(top != 0)
                {
                    cooldown_q.push(std::make_pair(top, clock+n+1));
                }
                prio_q.pop();
            }
        }
        return clock;
    }
};
// @lc code=end

