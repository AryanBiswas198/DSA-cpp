/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        int sum = 0;
        queue<int> q;
        q.push(id);

        while(!q.empty()) {
            int id = q.front();
            q.pop();

            Employee* e;
            for(auto emp: employees) {
                if(emp->id == id) {
                    e = emp;
                }
            }

            sum += e->importance;

            for(auto it: e->subordinates) {
                q.push(it);
            }
        }
        return sum;
    }
};