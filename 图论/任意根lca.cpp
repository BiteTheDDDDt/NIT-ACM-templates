int r,x,y;
int rx=lca(r,x),ry=lca(r,y);
if(rx==ry)printf("%d\n",lca(x,y));
else printf("%d\n",d(rx,r)<d(ry,r)?rx:ry);