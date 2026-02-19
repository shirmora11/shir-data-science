import json


def process_server_data(json_string):
    try:
        data = json.loads(json_string)
        data["status"] = "offline"
        return data
    except json.JSONDecodeError:
        print("error not a valid string")

    return json.dumps(data)

data_from_server = '{"id": 101, "status": "active", "authorized": true}'
print(process_server_data(data_from_server))
def common(l1,l2):
    comb = [num for num in l1 if num in l2]
    return comb
print(common([1,2,3,4,5],[5,6,7,8]))

def pointers(lis):
