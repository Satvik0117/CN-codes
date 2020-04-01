#include <string>
using namespace std;

template <typename V>
class MapNode{
    public:
	string key;
	V value;
	MapNode* next;

	MapNode(string key,V value){
		this->key=key;
		this->value=value;
		next=NULL;
	}
	~MapNode(){
		delete next;
	}

};

template <typename V>
class ourmap{
	MapNode<V>** buckets; // explanation in notes
	int count;
	int numbuckets;

public:

    double getLoadFactor(){
        return (1.0*count)/numbuckets;
    }

	ourmap(){
		count=0;
		numbuckets=5;
		buckets=new MapNode<V>*[numbuckets];
		for(int i=0;i<numbuckets;i++){
			buckets[i]=NULL;
		}
	}
	~ourmap(){
		for(int i=0;i<numbuckets;i++){
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size(){
		return count;
	}

	V getValue(string key){
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while(head!=NULL){
			if(head->key==key)
				return head->value;

			head=head->next;
		}
		//if key not found
		return 0;

	}

private:
	int getBucketIndex(string key){
		int hashCode=0;
		int currentCoeff=1;

		for(int i = key.length()-1;i>=0;i--){
			hashCode+=key[i]* currentCoeff;
			hashCode=hashCode %  numbuckets;
			currentCoeff*=37;
			currentCoeff=currentCoeff % numbuckets;
		}

		return hashCode % numbuckets;	//compression function
	}

	void rehash(){
		MapNode<V>** temp = buckets; // point to the old bucket
		buckets = new MapNode<V>*[2*numbuckets];
		for(int i=0;i<2*numbuckets;i++){
			buckets[i]=NULL;
		}
		int oldBucketCount = numbuckets;
		numbuckets*=2;
		count = 0;

		for(int i = 0; i < oldBucketCount; i++){
			MapNode<V>* head= temp[i];
			while(head != NULL){
				insert(head->key,head->value);
				head = head->next;
			}
		}

		for(int i = 0; i < oldBucketCount; i++){
			MapNode<V>* head = temp[i];
			delete head;
		}
		delete [] temp;
	}

public:
	void insert(string key, V value){
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		while(head !=NULL){
			if(head->key==key){
				head->value=value;
				return;
			}
			head=head->next;
		}
		head = buckets[bucketIndex];
		MapNode<V>* node = new MapNode<V>(key,value);
		node->next=head;
		buckets[bucketIndex]=node;
		count++;

		double loadFactor =(1.0*count)/numbuckets;
		if(loadFactor > 0.7){
			rehash();
		}
	}

	V remove(string key){
		int bucketIndex=getBucketIndex(key);
		MapNode<V>* head = buckets[bucketIndex];
		MapNode<V>* prev = NULL;
		MapNode<V>* temp = head;
		while(temp!=NULL){
			if(temp->key == key){
				if(prev==NULL){
					buckets[bucketIndex]=temp->next;
				}	else{
				prev->next=temp->next;//temp point to node we want to delete | temp->next is the one next of the node we want to delete
				}
				V value = temp->value;
				temp->next= NULL; //because of the recursive distructor we created
				delete head;
				count--;
				return value;
			}
			prev=temp;
			temp=temp->next;

		}
// if we reach here it means the value is not present so lets just return 0

		return 0;

	}



};
