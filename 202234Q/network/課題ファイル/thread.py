from time import sleep
import threading
Repeat = 5

def f1():
    for i in range(Repeat):
        print("f1", i)
        sleep(0.5)
def f2():
    for i in range(Repeat):
        print("f2", i)
        sleep(0.4)
def fx(n):
    for i in range(Repeat):
        print("fx", n, i)
        sleep(n)

if __name__ == '__main__':
    print("### start function call")
    f1()
    f2()
    fx(1)
    fx(2)
    print("### end function call")

    thread1 = threading.Thread(target=f1)
    thread2 = threading.Thread(target=f2)
    thread1x = threading.Thread(target=fx, args=(1,))
    thread2x = threading.Thread(target=fx, args=(2,))

    print("### start threads")
    thread1.start()
    thread2.start()
    thread1x.start()
    thread2x.start()
    print("### end threads???")

    thread1.join()
    thread2.join()
    thread1x.join()
    thread2x.join()
    print("### end threads!!!")