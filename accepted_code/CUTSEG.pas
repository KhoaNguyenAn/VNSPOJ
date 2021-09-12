uses math;
const
        tfi     =       '';
        tfo     =       '';
        nmax    =       200;
type
        arr1    =       array[0..100000] of char;
        arr2    =       array[0..100000] of longint;
        arr3    =       array[0..1000,'0'..'9'] of longint;
var
        fi,fo:text;
        n,m,res:longint;
        f,kq:array[0..nmax,0..nmax,0..nmax] of longint;
        a:arr1;
        s:string;
        vt:array['0'..'9'] of longint;
        d:arr3;
procedure nhap;
var i,j:longint;
begin
        assign(fi,tfi);reset(fi);
         readln(fi,n);
         for i:=1 to n do
         begin
          read(fi,a[i]);
          s:=s+a[i];
         end;
        close(fi);
end;
procedure khoitao;
var i:longint;
j:char;
begin
        for i:=n downto 1 do
         begin
           for j:='0'to '9' do
             d[i,j]:=vt[j];
           vt[a[i]]:=i;
         end;
end;
function xl(i,j,k:longint):longint;
var t,x1,x2:longint;
nho:longint;
begin
        if i>j then exit(sqr(k));
        if i=j then exit(sqr(k+1));
        if kq[i,j,k]=1 then exit(f[i,j,k]);
        xl:=0;
        nho:=0;
        for t:=i+1 to j do
         if a[t]<>a[i] then
          begin
           xl:=sqr(t-i+k)+xl(t,j,0);
           break;
          end;
      {  for t:=i+1 to j do
            if a[t]=a[i] then
             begin
             x1:=xl(i+1,t-1,0);
             x2:=xl(t,j,k+1);
              xl:=max(xl,xl(i+1,t-1,0)+xl(t,j,k+1));
             end;  }
        t:=d[i,a[i]];
        while (t>0)and(t<=j) do
          begin
            xl:=max(xl,xl(i+1,t-1,0)+xl(t,j,k+1));
            t:=d[t,a[t]];
          end;
        kq[i,j,k]:=1;
        f[i,j,k]:=xl;
end;
procedure inkq;
var i,j:longint;
begin
        assign(fo,tfo);rewrite(fo);
         res:=xl(1,n,0);
         writeln(fo,res);
        close(fo);
end;
begin
        nhap;
        khoitao;
        inkq;
end.