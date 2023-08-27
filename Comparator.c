SET , MAP , PRIORITY QUEUE CUSTOM COMPARATOR
class Compare {
public:
    bool operator()(pii a,pii b)
    {
        int len1=a.ss-a.ff+1;
        int len2=b.ss-b.ff+1;
        if(len1==len2)
        {
            return a.ff>b.ff;
        }
        return len1<len2;
    }
};
