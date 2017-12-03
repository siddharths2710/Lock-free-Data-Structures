import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;


public class FailFast {

	public static void main(String[] args) {


		Map<String,String> map = new ConcurrentHashMap<String,String>();
		map.put("1", "1");
		map.put("2", "1");
		map.put("3", "1");
		map.put("4", "1");
		map.put("5", "1");
		map.put("6", "1");
		System.out.println("ConcurrentHashMap before iterator: "+map);
		Iterator<String> it = map.keySet().iterator();
		String key;
		while(it.hasNext()){
			key = it.next();
			if(key.length() == 1) map.put(key+"new", "new" + map.get(key));
		}
		System.out.println("ConcurrentHashMap after iterator: "+map);


		map = new HashMap<String,String>();
		map.put("1", "1");
		map.put("2", "1");
		map.put("3", "1");
		map.put("4", "1");
		map.put("5", "1");
		map.put("6", "1");
		System.out.println("HashMap before iterator: "+map);
		Iterator<String> it1 = map.keySet().iterator();

		while(it1.hasNext()){
			key = it1.next();
			if(key.length() == 1) map.put(key+"new", "new" + map.get(key));
		}
		System.out.println("HashMap after iterator: "+map);
	}

}
