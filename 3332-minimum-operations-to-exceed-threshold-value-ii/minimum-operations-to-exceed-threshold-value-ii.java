class Solution {
    public int minOperations(int[] nums, int k) 
    {
        PriorityQueue<Long> p=new PriorityQueue<Long>();
		
		for(int i:nums)
		{
			p.add((long) i);
		}
		
		long val=0;
		int c=0;
		
		while (p.size() > 1 && p.peek() < k) { 
		    Long first_smallest = p.poll();
		    Long second_smallest = p.poll();

		    val = first_smallest * 2 + second_smallest;
		    
		    p.add(val);
		    c++;
		}
		
		return c;             
    }
}