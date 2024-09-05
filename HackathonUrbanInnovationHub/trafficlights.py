import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt


#read data
file = 'csv/kp18.csv'
td = pd.read_csv(file)
print(td.columns)
# pd.set_option('display.max_rows', None)
# print(td)
vehicles_list = []
route_list = []
cmap = plt.get_cmap('tab20')
unique_combinations = td.groupby(['VonArm', 'NachArm'])

#split data
for (col1_val, col2_val), group_td in unique_combinations:
    # Create a filename based on the unique values
    filename = f'{file} dataset_{col1_val}_to_{col2_val}.csv'
    filepath = os.path.join('datasets', filename)
    # Save the subset DataFrame to a CSV file
    group_td.to_csv(filepath, index=False)
i = 0,  
for (col1_val, col2_val), group_td in unique_combinations:
    # Create a filename based on the unique values
    filename = f'{file} dataset_{col1_val}_to_{col2_val}.csv'
    filepath = os.path.join('datasets', filename)
    dataset = pd.read_csv(filepath)
    dataset['Von'] = pd.to_datetime(dataset['Von'])
    plt.title(f'Time vs. Pkw {col1_val}_to_{col2_val}')
    vehicles = dataset['Pkw'] + dataset['Krad'] + dataset['Rad'] + dataset['Lieferfzg'] + dataset['Lieferfzg'] 
    + dataset['Lkw'] + dataset['Lastzug'] + dataset['Bus']
    vehicles_list.append(vehicles)
    route_list.append(f'{col1_val}_to_{col2_val}')
    


# visualize
plt.figure(figsize=(12, 8)) 
for i, vehicles in enumerate(vehicles_list):
    color = cmap(i / len(vehicles_list))
    plt.plot(dataset['Von'], vehicles, marker='o', linestyle='-',color=color ,label= route_list[i])
    i += 1
plt.xlabel('Time')
plt.ylabel('Pkw')
plt.legend()
plt.grid(True)
plt.tight_layout()
filepath = os.path.join('visualizations', file)
plt.savefig(f'{filepath}.pdf', dpi=150) 
# plt.show()






  # plt.plot(dataset['Von'], dataset['Krad'], marker='o', linestyle='-', label='Krad')
    # plt.plot(dataset['Von'], dataset['Rad'], marker='o', linestyle='-', label='Rad')
    # plt.plot(dataset['Von'], dataset['Lieferfzg'], marker='o', linestyle='-', label='Lieferfzg')
    # plt.plot(dataset['Von'], dataset['Lkw'], marker='o', linestyle='-', label='Lkw')
    # plt.plot(dataset['Von'], dataset['Lastzug'], marker='o', linestyle='-', label='Lastzug')
    # plt.plot(dataset['Von'], dataset['Bus'], marker='o', linestyle='-', label='Bus')# Replace 'value' with your numerical column
    