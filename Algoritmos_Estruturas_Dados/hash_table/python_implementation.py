# Function to display hashtable
def display_hash(hashTable):
	
	for i in range(len(hashTable)):
		print(i, end = " ")
		
		for j in hashTable[i]:
			print("-->", end = " ")
			print(j, end = " ")
			
		print()


N = int(input())

# Creating Hashtable as
# a nested list.
HashTable = [[] for _ in range(1, N + 1, 1)]

# Hashing Function to return
# key for every value.
def Hashing(keyvalue):
	return keyvalue % len(HashTable)


# Insert Function to add
# values to the hash table
def insert(Hashtable, keyvalue, value):
	
	hash_key = Hashing(keyvalue)
	Hashtable[hash_key].append(value)

def remove(Hashtable, value):
    hash_key = Hashing(value)
    Hashtable[hash_key].remove(value)

# Driver Code
arr = list(map(int, input().split()))
arr.sort()
arr.remove(-1)
print(arr)
for i in range(len(arr)):
    insert(HashTable, i, arr[i])



num = int(input())

display_hash (HashTable)
print()
remove(HashTable, num)


'''insert(HashTable, 10, 'Allahabad')
insert(HashTable, 25, 'Mumbai')
insert(HashTable, 20, 'Mathura')
insert(HashTable, 9, 'Delhi')
insert(HashTable, 21, 'Punjab')
insert(HashTable, 21, 'Noida')'''

display_hash (HashTable)
