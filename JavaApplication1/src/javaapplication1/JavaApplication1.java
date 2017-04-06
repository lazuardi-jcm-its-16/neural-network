/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author rif
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //System.out.println(findPrettyNumber(new Long("100")));
        //System.out.println(findPrettyNumber(new Long("200")));
        //System.out.println(findPrettyNumber(new Long("300")));
        //System.out.println(findPrettyNumber(new Long("400")));
        Long a = findPrettyNumber(new Long("100"));
        Long b = findPrettyNumber(new Long("500"));
        System.out.println(a);
        System.out.println(b);
        System.out.println(a+b);
    }
    
    static ArrayList<Long> arrayPrime = new ArrayList<>();
    static ArrayList<Long> prettyNumber = new ArrayList<>();
    
    static Long findPrettyNumber(Long x) {
        Long idx = new Long("0");
        if(prettyNumber.size() > 0)
            idx = new Long(prettyNumber.size());
        
        Long i = new Long("0");
        if(prettyNumber.size() > 0)
            i = prettyNumber.get(prettyNumber.size()-1);
        
        while(true) {
            i++;
            if(isPrettyNumber(i)){
                idx++;
                prettyNumber.add(i);
                if(idx.equals(x))
                    break;
            }
        }
        return i;
    }
    
    static boolean isPrettyNumber(Long x) {
        if(x.equals(new Long("1")))
            return true;
        
        return largePrimeFactors(x) <= 5;
    }
    
    
    public static Long largePrimeFactors(Long numbers) {
        Long i;

        for (i = new Long("2"); i <= numbers; i++) {
            if (numbers % i == 0) {
                numbers /= i;
                i--;
            }
            if(i>5)
                break;
        }

        return i;
    }

    public static List<Long> primeFactors(Long numbers) {
        Long n = numbers;
        List<Long> factors = new ArrayList<>();
        for (Long i = new Long("2"); i <= n / i; i++) {
            while (n % i == 0) {
                factors.add(i);
                n /= i;
            }
        }
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }
    
    
   
    
}
