import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;

public class RegistrationSystem {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        String line = reader.readLine();
        if (line == null) return;
        
        int n = Integer.parseInt(line.trim());
        HashMap<String, Integer> db = new HashMap<>();
        StringBuilder output = new StringBuilder();

        while (n-- > 0) {
            String name = reader.readLine().trim();

            if (!db.containsKey(name)) {
                db.put(name, 1);
                output.append("OK\n");
            } else {
                int count = db.get(name);
                output.append(name).append(count).append("\n");
                db.put(name, count + 1);
            }
        }

        System.out.print(output);
    }
}