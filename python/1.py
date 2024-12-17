import asyncio


class CWFuture:

    def join():
        pass

    def isDone() -> bool:
        pass

    def add_callback():
        pass


"""
Instatiate a Queue:
Add these objects.

Iterate the queue:
check if the objects are done:

if the objects are done then remove them from queue, else add them back to the queue.
do this till the queue is empty.

Problem: wasted iteration:


now instead of that, 


Lets use HashSet. 

add all the CWFuture objects to the SET.

In the CWFuture add a method when we change the done from false to true, we call that method.

this method removes the object from the set and add result to the final value.

Let us also give an error callback - that is in case of errors, we can try to fix something.
"""

def count_words(lap_id, file_id) -> CWFuture:
    pass


class Result:

    laptop_id: int
    file_id: int
    total_words: int

class TotalWords:

    def __init__(self, files_count, laptop_count) -> None:
        self.files_count = files_count
        self.laptop_count = laptop_count

        self.files_processed = []
        self.files_underprocessing = set()

        self.words_count = 0

    def is_retryable(err):
        pass

    def res_callback(self, res: Result, err):
        if err:
            if self.is_retryable(err):
                self.add_task(res.file_id, res.laptop_id)
            else:
                raise err

        self.words_count += res.total_words
        self.files_processed.append(res.file_id)
        self.files_underprocessing.remove(res.file_id)

    def add_task(self, file_id, laptop_id):
        res = count_words(file_id, laptop_id)
        self.files_underprocessing.add(file_id)
        res.add_callback(self.res_callback)
    

    async def get_total_words(self):
        
        for i in range(self.laptop_count):
            self.add_task(i, i)

        while len(self.files_processed) < self.files_count:
            asyncio.sleep(0.5)

        return self.words_count

