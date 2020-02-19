import java.util.Scanner;
public class Main {
    static int n,m,k;
    static long d[]=new long[10000001],o[]=new long[1000001];
    static void update(int p,long v){
        while(p<=n){
            d[p]+=v;
            p+=(p&-p);
        }
    }
    static long sum(int p){
        long s=0;
        while(p>0){
            s+=d[p];
            p-=(p&-p);
        }
        return s;
    }
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        n=sc.nextInt();
        m=sc.nextInt();
        k=sc.nextInt();
        m+=k;
        for(int i=1;i<=n;i++){
            int x=sc.nextInt();
            o[i]=x;
            update(i,x);
        }
        for(int i=0;i<m;i++){
            int x=sc.nextInt();
            int y=sc.nextInt();
            int z=sc.nextInt();
            if(x==1){
                update(y,z-o[y]);
                o[y]=z;
            }else {
                System.out.println(sum(z)-sum(y-1));
            }
        }
    }
}