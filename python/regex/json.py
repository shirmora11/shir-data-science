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
