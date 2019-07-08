import java.util.*;

class LexicoLarger {
  void lexicoHstring(String str, String osf, boolean bool){
      String result;
      if(str.length() == 0) {
        result = osf;
        System.out.println(result);
        return ;
      }
      for(int i=0;i<str.length();i++){
        if(bool) {
          char ch = str.charAt(i);
          String ros = str.substring(0, i) + str.substring(i+1);
          lexicoHstring(ros, osf+ch, bool);
        }
        else {
          if(str.charAt(i) >= str.charAt(0)) {
            char ch = str.charAt(i);
            String ros = str.substring(0, i) +str.substring(i+1);
            lexicoHstring(ros, osf+ch,bool || ch>str.charAt(0));
          }
        }
      }
    }
  }

class mainne {
    public static void main(String[] args) {
        LexicoLarger l = new LexicoLarger();
        Scanner s = new Scanner(System.in);
        String s1 = s.nextLine();
    l.lexicoHstring(s1, "", false);
  }
}
