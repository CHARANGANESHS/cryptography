import pandas as pd
import json

if __name__ == "__main__"
    with open("train.json", "r") as json_file:
        data = json.load(json_file)

    df = pd.json_normalize(data)

    df.to_csv("train.csv", index=False)

    print("JSON file converted to test.csv successfully!")

