#inventory system

#starting supplies
stuff = {'rope': 1,
         'torch': 6,
         'gold coin': 42,
         'dagger': 1,
         'arrow': 12}


def displayInventory(inventory):
    print("Inventory: ")
    item_total = 0
    for k, v in inventory.items():
        print(str(v), str(k))
        item_total = item_total + inventory[k]

    print('Total number of items: ' + str(item_total))

displayInventory(stuff)

def addToInventory(inventory, addedItems):
    loot = 0
    for i in addedItems:
        item = addedItems[loot]
        if item in inventory:
            inventory[item] += 1
        else:
            inventory[item] = 1
        loot += 1
    return inventory
print('CONGRATULATIONS!!!')
print('You kileed the dragon!!!')
#inv = {'gold coin': 42, 'rope': 1}
dragonLoot = ['gold chain', 'dagger', 'gold coin', 'gold coin', 'ruby']
#inv = addToInventory(inv, dragonLoot)
stuff = addToInventory(stuff, dragonLoot)

displayInventory(stuff)
