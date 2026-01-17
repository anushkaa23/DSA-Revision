/*
Book Allocation
You have N books, where the i-th book has A[i] pages. There are M students.

You need to distribute all books to the students with these rules:

Each student must get at least one book.
Each book can be given to only one student.
The books given to a student must be next to each other (contiguous).
Your task is to distribute the books so that the maximum pages any student gets is as small as possible.

If it is not possible to distribute the books, print -1.

Input Format
First line: two integers N (number of books) and M (number of students).
Second line: N integers, where A[i] = pages in the i-th book.
Output Format
Print the minimum possible value of the maximum pages assigned to a student.
If distribution is not possible, print -1.
Sample Input
4 2
12 34 67 90
Your Output
113
*/

/*
Approach:

If the number of students (M) is greater than the number of books (N),
then it is not possible to allocate at least one book to each student,
so we return -1.

The minimum possible value of the maximum pages assigned to a student
must be at least the maximum pages in any single book, because a book
cannot be divided.

The maximum possible value can be the sum of all pages, which happens
when all books are assigned to one student.

So, the answer lies in the range:
[max_element(books), sum_of_all_books]

We apply Binary Search on this range.

For a given value (mid), we check if it is possible to distribute all
books among M students such that no student gets more than mid pages.

To check feasibility:
- We assign books in order (contiguous allocation).
- Keep adding books to the current student until the limit is exceeded.
- If the limit is exceeded, assign the next book to a new student.
- Count how many students are required.
- If the number of students required is less than or equal to M,
  the allocation is possible.

Binary Search logic:
- If allocation is possible with mid pages, try to minimize the answer
  by moving to the left side.
- If allocation is not possible, increase the limit by moving to the
  right side.

Finally, return the minimum possible value of the maximum pages that can
be assigned to any student.

Time Complexity:
- O(N log S), where N is the number of books and S is the sum of pages.

Space Complexity:
- O(1), since only constant extra space is used.
*/

bool check(vector<long long>& books, int M , int limit){
    long long sum=0;
    int n=books.size();
    int cnt=1;
    for(int i=0;i<n;i++){
        if(books[i]>limit) return false;
        if(sum+books[i]>limit){
            sum=books[i];
            cnt++;
        }
        else sum+=books[i];
    }
    return (cnt<=M);
}
long long allocateBooks(vector<long long>& books, int N, int M) {
    // complete the logic...
    if(M>N) return -1;
    long long low=*max_element(books.begin(),books.end());
    long long high=accumulate(books.begin(),books.end(),0LL);
    long long res=-1;
    while(low<=high){
        long long mid=(low+high)/2;
        if(check(books,M,mid)){
            high=mid-1;
            res=mid;
        }else low=mid+1;
    }
    return res;
}