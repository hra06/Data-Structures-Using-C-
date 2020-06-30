#include<vector>
using namespace std;


class PriorityQueue{
	vector<int> pq;
	
	public:
		PriorityQueue(){
		
		}
		
		bool isEmpty(){
			return (pq.size() == 0);
		}
		
		int getSize(){
			return pq.size();
		}
		
		int getMin(){
			if(isEmpty()){
				return 0;
			}
			return pq[0];
		}
		
		void insert(int element){
			pq.push_back(element);
			
			int childIndex = pq.size()-1;
			
			//while(pq[childIndex] >= pq[parentIndex]){
			while(childIndex > 0){				
				int parentIndex = (childIndex-1)/2;
			
				if(pq[childIndex] <pq[parentIndex]){
					int temp = pq[childIndex];
					pq[parentIndex] = pq[childIndex];
					pq[parentIndex] = pq[childIndex];
				}else{
					break;
				}
				parentIndex = (childIndex-1)/2;
			}
			
		}
};
