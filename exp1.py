size = 3
list = [None]*size


def add():
    id = int(input("Enter the ID : "))
    name = input("Enter Name : ")
    phone = int(input("Enter Phone No. : "))
    index = id % size
    details = [id,name,phone]
    for i in range(size):
        if list[index] == None:
            list[index] = details
            break
        index = (index +1)% size

def search():
    id = int(input("Enter the ID : "))
    index = id % size

    for i in range(size):
        if list[index] != None:
            if list[index][0]== id:
                print("ID found at ",index)
                print("Details : ",list[index])
                break
            index = (index + 1)% size

def delete():
    id = int(input("Enter the ID : "))
    index = id&size

    for i in range(size):
        if list[index] !=None:
            if list[index][0]== id:
                print("Record ",list[index]," Deleted.")
                list[index]= None
            index = (index +1)% size
    

add()
add()
add()
print(list)
search()
delete()
print(list)
