class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return false;
    
        // cout<<mrx<<" "<<mry;
        if(sx<=fx && sy<=fy)
        {
            int mReachX=sx+t;
            int mReachY=sy+t;
            if(mReachX>=fx && mReachY>=fy) return true;

        }
        else if(sx>=fx && sy>=fy)
        {
            int mrx=sx-t;
            int mry=sy-t;
            cout<<"2->"<<mrx<<" "<<mry;
            if(mrx<=fx && mry<=fy) return true;
        }
        else if(sx<=fx && sy>=fy)
        {
            int mrx=sx+t;
            int mry=sy-t;
            cout<<"3->"<<mrx<<" "<<mry;
            if(mrx>=fx && mry<=fy) return true;
        }
        else
        {
            int mrx=sx-t;
            int mry=sy+t;
            cout<<"4->"<<mrx<<" "<<mry;
            if(mrx<=fx && mry>=fy) return true;
        }
            
            
        
        return false;
    }
};









































