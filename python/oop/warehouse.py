class Warehouse:
    def __init__(self,dic):
        self._data = dic
    @property
    def data(self):
        return self._data
    @data.setter
    def data(self,new_data):
        self._data = new_data
    def __len__(self):
        return len(self._data)
    def add_product(self,name,price):
        if name in self.data and price < self.data[name]:
            self._data[name] = price
        else:
            self.data.setdefault(name,price)
    def get_average_price(self):
        return (sum(self.data.values()))/len(self.data)
    def __str__(self):
        return f"this warehouse has {len(self._data)} products"
    def __add__(self, other):
        if not isinstance(other, Warehouse):
            raise TypeError("Can only add another Warehouse")
        result = {**self.data, **other.data}
        return Warehouse(result)
    def __getitem__(self, item):
        return self._data.get(item, "Not found")


class ColdWarehouse(Warehouse):
    def __init__(self, dic, temperature):
        super().__init__(dic)
        self._temp= temperature
    @property
    def temp(self):
        return self._temp

    def add_product(self, name, price):
        if self._temp > 0:
            print("המחסן חם מדי! אי אפשר להוסיף מוצר.")
        else:
            super().add_product(name , price)



w1 = Warehouse({"apple": 5, "banana": 3})
w2 = Warehouse({"orange": 10})

print(w1)
print(w1["apple"])
w3 = w1 + w2
print(w3["orange"])