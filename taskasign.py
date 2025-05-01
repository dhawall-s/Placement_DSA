lass Solution(object):
    def maxTaskAssign(self, tasks, workers, pills, strength):
        tasks.sort()
        workers.sort()
        
        n = len(tasks)
        m = len(workers)
        
        left, right = 0, min(n, m)
        
        def canAssign(numTasks):
            pillCount = pills
            taskIdx = numTasks - 1  # Start from the last task (strongest task)
            workerIdx = m - 1      # Start from the last worker (strongest worker)
            
            while taskIdx >= 0 and workerIdx >= 0:
                if workers[workerIdx] >= tasks[taskIdx]:
                    # Worker can handle the task without a pill
                    workerIdx -= 1
                    taskIdx -= 1
                elif pillCount > 0 and workers[workerIdx] + strength >= tasks[taskIdx]:
                    # Worker can handle the task with a pill
                    pillCount -= 1
                    workerIdx -= 1
                    taskIdx -= 1
                else:
                    # Worker cannot handle the task, move to the next worker
                    workerIdx -= 1
            
            return taskIdx < 0  # If all tasks have been assigned
        
        while left < right:
            mid = left + (right - left + 1) // 2  # Test for the middle number of tasks
            if canAssign(mid):
                left = mid  # If we can assign 'mid' tasks, try more tasks
            else:
                right = mid - 1  # Otherwise, reduce the number of tasks
        
        return left