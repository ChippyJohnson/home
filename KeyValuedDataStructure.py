dictionary_tk = {
  "name": "Leandro",
  "nickname": "Tk",
  "nationality": "Brazilian",
}

dictionary_tk['age'] = 24

print(dictionary_tk)
print("My name is %s" %(dictionary_tk["name"])) # My name is Leandro
print("But you can call me %s" %(dictionary_tk["nickname"])) # But you can call me Tk
print("And by the way I'm %i and %s" %(dictionary_tk["age"], dictionary_tk["nationality"])) # And by the way I'm Brazilian





for key in dictionary_tk:
    print("%s --> %s" %(key, dictionary_tk[key]))


for attribute, value in dictionary_tk.items():
    print("My %s is %s" %(attribute, value))
