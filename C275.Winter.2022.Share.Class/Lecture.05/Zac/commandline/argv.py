import sys

def basemain():
    argc = len(sys.argv)
    print("Number of parameters: ",argc)
#    for f in sys.argv:
#        print(f)

    for i in range(argc):
        print("argv[%d] = %s"%(i,sys.argv[i]))

    return


if __name__ == "__main__":
    basemain()
