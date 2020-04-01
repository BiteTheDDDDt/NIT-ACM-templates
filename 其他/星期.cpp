const int md[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
struct Calendar
{
    int y,m,d;
    bool isLeap(){return (y%100!=0&&y%4==0||y%400==0);}
    bool isCalendar(){return !(y<1600||y>9999||m>12||m<1||d<1||d>md[isLeap()][m]);}
    int getWeek(){return (d+1+2*(m+(m<3)*12)+3*(m+(m<3)*12+1)/5+y-(m<3)+(y-(m<3))/4-(y-(m<3))/100+(y-(m<3))/400)%7;}//0为周日
    int getDist(Calendar x)
    {
        int res=(y-1)*365+(y-1)/4-(y-1)/100+y/400+d-((x.y-1)*365+(x.y-1)/4-(x.y-1)/100+(x.y-1)/400+x.d);
        for(int i=1;i<m;i++)res+=md[isLeap()][i];
        for(int i=1;i<x.m;i++)res-=md[x.isLeap()][i];
        return res;
    }
};