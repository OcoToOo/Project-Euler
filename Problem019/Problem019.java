import java.util.Calendar;

public class Problem019 {
    public static void main(String[] args) {
        final Calendar calendar = Calendar.getInstance();
        long num = 0;
        for (int year = 1901; year <= 2000; ++year) {
            for (int month = 0; month <= 11; ++month) {
                calendar.set(year, month, 1);
                if (calendar.get(Calendar.DAY_OF_WEEK) == Calendar.SUNDAY) num++;
            }
        }
        system.out.print(num);
    }
}
