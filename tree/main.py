from queue import Queue
class Throne:
    def __init__(self, first_king_name):
        self.now_king = first_king_name
        self.all_persons = dict()
        self.all_persons[self.now_king] = 0
        self.q = Queue()
    
    def marry(self, first_spouse_id, second_spouse_name):
        self.q.put(second_spouse_name)
        self.all_persons[second_spouse_name] = 0
    
    def new_born(self, first_parent_id, second_parent_id, name):
        self.q.put(name)
        self.all_persons[name] = 0
    
    def die(self, id):
        self.all_persons[id] = 1
        if (id == self.now_king):
            self.now_king = self.q.get()
            while (self.all_persons[self.now_king] == 1):
                self.now_king = self.q.get()
    
    def who_is_the_king(self):
        return self.now_king
t = Throne(input())
while 1:
    command = input().split()
    if (command[0] == "marry"):
        t.marry(command[1], command[2])
    elif (command[0] == "born"):
        t.new_born(command[1], command[2], command[3])
    elif (command[0] == "die"):
        t.die(command[1])
    elif (command[0] == "get_king"):
        print(t.who_is_the_king())
    elif (command[0] == "exit"):
        print("bye")
        break
