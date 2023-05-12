import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.util.HashMap;
import java.util.Map;
import java.io.PrintWriter;

public class project3 {

   public static void main(String[] args) {

      HashMap<String, State> schema = new HashMap<String, State>();
      HashMap<String, String> stateSchema = new HashMap<String, String>();
                                                                                    
      HashMap<String, String> maxPopulationZipcode = new HashMap<String, String>(); 
      HashMap<String, String> minPopulationZipcode = new HashMap<String, String>(); 
      HashMap<String, String> maxAvgWagesZipcode   = new HashMap<String, String>(); 
      HashMap<String, String> minAvgWagesZipcode   = new HashMap<String, String>(); 


      maxPopulationZipcode.put("population", "0");
      minPopulationZipcode.put("population", "99999999");

      maxAvgWagesZipcode.put("avgWages", "0");
      minAvgWagesZipcode.put("avgWages", "99999999");
      
      
      if(args.length != 2) {
         System.out.println("An Error has occurred during processing.<br>");
         System.out.println("Error: Incorrect amount of arguments<br>");

         System.out.println("<br>Amount of Arguments: " + args.length);
         System.out.println("<br>Args:");
         for(String x: args) {
            System.out.println(x + "<br>");
         }
         System.exit(0);
      }
      
      try {

         
         BufferedReader input = new BufferedReader(new FileReader(args[0]));

         input.readLine();

         for(String row = input.readLine(); row != null; row = input.readLine()) {
            String[] tokens = row.split(",");
            stateSchema.put(tokens[1], tokens[3]);
         }     

         input.close();

         
         input = new BufferedReader(new FileReader(args[1]));

         input.readLine();

         
         for(String row = input.readLine(); row != null; row = input.readLine()) {
            String[] tokens = row.split(",");

            int population = Integer.parseInt(tokens[18]);

            double avgWages = tokens.length < 20 ? 0 : Double.parseDouble(tokens[20]);

            if(schema.containsKey(tokens[4]))                
               schema.get(tokens[4]).addZipcode(population, 
               avgWages);
            else
               schema.put(tokens[4], new State(stateSchema.get(tokens[4]),
                population, avgWages));

    
            if(Integer.parseInt(maxPopulationZipcode.get("population")) < population) {
               fillDataSet(maxPopulationZipcode, tokens[1], tokens[4], 
               tokens[3], tokens[18], avgWages);
            }
       else if(Integer.parseInt(minPopulationZipcode.get("population")) > population) {
               fillDataSet(minPopulationZipcode, tokens[1], tokens[4], 
               tokens[3], tokens[18], avgWages);
            }

            if(Double.parseDouble(maxAvgWagesZipcode.get("avgWages")) < avgWages) {
               fillDataSet(maxAvgWagesZipcode, tokens[1], tokens[4], 
               tokens[3], tokens[18], avgWages);
            }
       else if(Double.parseDouble(minAvgWagesZipcode.get("avgWages")) > avgWages && avgWages != 0) {
               fillDataSet(minAvgWagesZipcode, tokens[1], tokens[4], 
               tokens[3], tokens[18], avgWages);
            }

         }

        
         PrintWriter output = new PrintWriter(new File("Project3_results.html"));
         printResults(schema, output, maxPopulationZipcode, minPopulationZipcode,
          maxAvgWagesZipcode, minAvgWagesZipcode);

        
         output = new PrintWriter(System.out);
         printResults(schema, output, maxPopulationZipcode, minPopulationZipcode,
          maxAvgWagesZipcode, minAvgWagesZipcode);


      }

      catch (NumberFormatException e) {
         System.out.println("An Error has occurred during processing.<br>");
         System.out.println("An incorrect data type has been detected. Please check your input file and try again.");
      }

      catch (ArrayIndexOutOfBoundsException e) { 
         System.out.println("An Error has occurred during processing.<br>");
         System.out.println("A record related error has been detected (multiple missing columns and fields in row,possible corruption). Please check your input file and try again.");
      }

      catch (Exception e) {
         System.out.println("A Generic Error has occurred during processing. Please check your input file.<br><br>");
         System.out.println("Error message:<br>");
         e.printStackTrace();
      } 

   }


 
   static void fillDataSet(HashMap<String, String> dataSet, 
   String zipcode, String state, 
   String city, String population, double avgWages) {
       dataSet.put("zipcode", zipcode);
       dataSet.put("state", state);
       dataSet.put("city", city);
       dataSet.put("population", population);
       dataSet.put("avgWages", "" + avgWages);
   }


   
   static void printResults(HashMap<String, 
   State> schema, PrintWriter output,
    HashMap<String, String> maxPop, 
    HashMap<String, String> minPop,
     HashMap<String, String> maxAvgWages,
      HashMap<String, String> minAvgWages) {
       output.println("<Table border = 1>");

       output.println("<tr> <th>State</th> <th>Capital</th> <th>Number_of_Zipcodes</th> <th>Total_Estimated_Population</th> <th>Average_AvgWages</th> </tr>");

       schema.entrySet().stream()                                                                                     
           .sorted( Map.Entry.<String, State> comparingByValue() )                                                    
           .forEach( entry -> { output.println("<tr> <td>" + entry.getKey() + "</td>"
             + entry.getValue()); } );  
         
       output.println("</Table>");
  
       output.printf("<br>Zipcode %s at %s, %s has the maximum population %, d with AvgWages $ %,.1f",
        maxPop.get("zipcode"),
         maxPop.get("city"), 
         maxPop.get("state"),
          Integer.parseInt(maxPop.get("population")), 
          Double.parseDouble(maxPop.get("avgWages")));
       output.printf("\n<br>Zipcode %s at %s,  %s has the minimum population %, d with AvgWages $ %,.1f", 
       minPop.get("zipcode"), minPop.get("city"), 
       minPop.get("state"), 
       Integer.parseInt(minPop.get("population")),
        Double.parseDouble(minPop.get("avgWages")));
       output.printf("<br>Zipcode %s at %s, %s has the maximum AvgWages $ %,.1f with population %,d", 
       maxAvgWages.get("zipcode"), 
       maxAvgWages.get("city"), 
       maxAvgWages.get("state"),
        Double.parseDouble(maxAvgWages.get("avgWages")), 
        Integer.parseInt(maxAvgWages.get("population")));
       output.printf("<br>Zipcode %s at %s,%s has the minimum AvgWages $ %,.1f with population %,d", 
       minAvgWages.get("zipcode"), 
       minAvgWages.get("city"), 
       minAvgWages.get("state"), 
       Double.parseDouble(minAvgWages.get("avgWages")),
        Integer.parseInt(minAvgWages.get("population")));
       output.close();
   }



   private static class State implements Comparable<State>{
         
       String capital;
       int numberOfZipcodes = 1;
       int numberOfZipcodesWithoutAverage = 0;
       int population;
       double totalAvgSalary;


    State(String capital, int population, double AvgSalary) {
       this.capital = capital;
       this.population = population;

       if(AvgSalary == 0)
          numberOfZipcodesWithoutAverage++;
       else
          this.totalAvgSalary = AvgSalary;
    }


    
       void addZipcode(int population, double avgSalary) {
          totalAvgSalary += avgSalary;
          this.population += population;
          numberOfZipcodes++;

          if(avgSalary == 0)
             numberOfZipcodesWithoutAverage++;
       }
        
        
       double getAverageAvgSalary() {
          return totalAvgSalary / 
          (numberOfZipcodes - numberOfZipcodesWithoutAverage);
       }

       
       public int compareTo(State o2) { 
          double salary1 = getAverageAvgSalary();
          double salary2 = o2.getAverageAvgSalary();

          if(salary1 == salary2)
             return 0;

          return salary1 > salary2 ? -1 : 1;

       }

       
       public String toString() {
          return String.format(" <td>%s</td> <td align='right'>%d</td> <td align='right'>%,d</td> <td align='right'>$ %,.1f</td> </tr>",
           capital, numberOfZipcodes, population, getAverageAvgSalary());
       }
      
   }
}