import java.util.concurrent.ConcurrentHashMap;
class CMapDemo implements Runnable {
   private Thread t;
   private String threadName;
   private ConcurrentHashMap<String,String> mapRef;
   private String key = null;
   private String value = null;

   CMapDemo(ConcurrentHashMap<String,String> cmap,String name,String key) {
      threadName = name;
      this.key = key;
      mapRef = cmap;

      System.out.println("Creating " +  threadName + " to get value of key: " + key);
   }
   

   CMapDemo(ConcurrentHashMap<String,String> cmap,String name,String key,String value) {
      threadName = name;
      this.key = key;
      this.value = value;
      mapRef = cmap;
      
      System.out.println("Creating " +  threadName + " to insert key:" + key + " and value: " + value);
   }


   public void run() {
      System.out.println("Running " +  threadName );
      try {
         

         if(value != null)
         {
            mapRef.put(key,value);

         }
         else
         {
            if(mapRef.containsKey(key))
            {
               System.out.println( " Thread " + threadName + " get value: " + mapRef.get(key) ) ;
            }
            else{

               System.out.println( " Thread " + threadName + " get request key not found ") ;  
            }
         }
         System.out.println("Thread " + threadName + " request fulfilled" );

      } catch (Exception e) {
         System.out.println("Thread " +  threadName + " interrupted.");
      }
      System.out.println("Thread " +  threadName + " exiting.");
   }
   
   public void start () {
      System.out.println("Starting " +  threadName );
      if (t == null) {
         t = new Thread (this, threadName);
         t.start ();
      }
   }
}

public class ThreadDemo {

   public static void main(String args[]) {
      
      ConcurrentHashMap<String,String> cmap = new ConcurrentHashMap<String,String>();
      CMapDemo T1 = new CMapDemo(cmap,"Thread-1","1","1");
      CMapDemo T2 = new CMapDemo(cmap,"Thread-2","2","2");
      CMapDemo T3 = new CMapDemo(cmap,"Thread-3","3","3");
      CMapDemo T4 = new CMapDemo(cmap,"Thread-4","2");

      T1.start();
      T2.start();
      T3.start();
      T4.start();
      
   }   
}
