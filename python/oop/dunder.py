class datafolder:
    def __init__(self,lis):
        self.data = lis
    def __len__(self):
        return len(self.data)
    def __str__(self):
        return f"this folder contain {len(self.data)}"
my_folder = datafolder([10, 20, 30,40])
print(len(my_folder))
print(my_folder)

class databasket:
    def __init__(self,lis):
        self.data = lis
    def __add__(self, other):
        new_list = self.data + other.data
        return databasket(new_list)
    def __gt__(self, other):
        avg_self = sum(self.data) / len(self.data)
        avg_other = sum(other.data) / len(other.data)
        return avg_self > avg_other