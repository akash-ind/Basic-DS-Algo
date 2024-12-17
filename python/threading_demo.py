import threading

from time import sleep

count = 0

def increase_count(condition: threading.Condition):
    global count
    print(f"Increasing count by thread - {threading.get_ident()}")

    condition.acquire()
    print(f"Lock acquired by thread - {threading.get_ident()}")
    sleep(2)
    count += 1
    # condition.notify_all()
    print(f"Notified all - {threading.get_ident()}")
    condition.release()
    
    print(f"Released lock by thread - {threading.get_ident()}")


def print_count(condition: threading.Condition):

    condition.acquire()
    print(f"Acquired lock by thread - {threading.get_ident()}")
    print(f"Waiting for lock by thread - {threading.get_ident()}")
    condition.wait()
    condition.release()

    print(f"thread - {threading.get_ident()} -- count value  - {count}")



def main():
    lock = threading.Lock()
    condition = threading.Condition(lock)

    t1 = threading.Thread(target=increase_count, args=[condition])
    t2 = threading.Thread(target=print_count, args=[condition])

    t2.start()
    sleep(5)
    t1.start()    

if __name__ == "__main__":
    main()
