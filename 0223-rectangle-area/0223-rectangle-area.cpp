class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
        int length1 = abs(ax1 - ax2), bredth1 = abs(ay1 - ay2), length2 = abs(bx1 - bx2), bredth2 = abs(by1 - by2);
        int area = length1*bredth1 + length2*bredth2;
        int area_bit = 0;
        if(ax1 <= bx1 and ax2 >= bx1 and bx2 >= ax2){
            int temp_length = abs(ax2 - bx1);
            int temp_bredth = 0;
            if(ay1 <= by1 and by2 >= ay2 and ay2 >= by1){
                temp_bredth = abs(ay2 - by1);
            }else if(ay1 >= by1 and by2 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - ay1);
            }else if(by1 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - by1);
            }else if(ay1 >= by1 and ay2 <= by2){
                temp_bredth = abs(ay2 - ay1);
            }
            area_bit = temp_length*temp_bredth;
        }else if(ax1 <= bx1 and bx2 <= ax2){
            int temp_length = abs(bx2 - bx1);
            int temp_bredth = 0;
            if(ay1 <= by1 and by2 >= ay2 and ay2 >= by1){
                temp_bredth = abs(ay2 - by1);
            }else if(ay1 >= by1 and by2 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - ay1);
            }else if(by1 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - by1);
            }else if(ay1 >= by1 and ay2 <= by2){
                temp_bredth = abs(ay2 - ay1);
            }
            area_bit = temp_length*temp_bredth;
        }else if(bx1 <= ax1 and bx2 >= ax1 and bx2 <= ax2){
            int temp_length = abs(bx2 - ax1);
            int temp_bredth = 0;
            if(ay1 <= by1 and by2 >= ay2 and ay2 >= by1){
                temp_bredth = abs(ay2 - by1);
            }else if(ay1 >= by1 and by2 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - ay1);
            }else if(by1 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - by1);
            }else if(ay1 >= by1 and ay2 <= by2){
                temp_bredth = abs(ay2 - ay1);
            }
            area_bit = temp_length*temp_bredth;
        }else if(bx1 <= ax1 and ax2 <= bx2){
            int temp_length = abs(ax2 - ax1);
            int temp_bredth = 0;
            if(ay1 <= by1 and by2 >= ay2 and ay2 >= by1){
                temp_bredth = abs(ay2 - by1);
            }else if(ay1 >= by1 and by2 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - ay1);
            }else if(by1 >= ay1 and by2 <= ay2){
                temp_bredth = abs(by2 - by1);
            }else if(ay1 >= by1 and ay2 <= by2){
                temp_bredth = abs(ay2 - ay1);
            }
            area_bit = temp_length*temp_bredth;
        }
        return area - area_bit;
    }
};