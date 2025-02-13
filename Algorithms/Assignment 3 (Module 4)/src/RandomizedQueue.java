import java.util.Iterator;
import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] queue;
    private int size;

    public RandomizedQueue() {
        queue = (Item[]) new Object[2];
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    private void resize(int capacity) {
        Item[] temp = (Item[]) new Object[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = queue[i];
        }
        queue = temp;
    }

    public void enqueue(Item item) {
        if (item == null) throw new IllegalArgumentException();
        if (size == queue.length) resize(2 * queue.length);
        queue[size++] = item;
    }

    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException();
        int randomIndex = StdRandom.uniform(size);
        Item item = queue[randomIndex];
        queue[randomIndex] = queue[size - 1];
        queue[size - 1] = null;
        size--;
        if (size > 0 && size == queue.length / 4) resize(queue.length / 2);
        return item;
    }

    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException();
        return queue[StdRandom.uniform(size)];
    }

    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int current;
        private final Item[] shuffledQueue;

        public RandomizedQueueIterator() {
            shuffledQueue = (Item[]) new Object[size];
            for (int i = 0; i < size; i++) {
                shuffledQueue[i] = queue[i];
            }
            StdRandom.shuffle(shuffledQueue);
            current = 0;
        }

        public boolean hasNext() {
            return current < shuffledQueue.length;
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            return shuffledQueue[current++];
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public static void main(String[] args) {
        RandomizedQueue<String> rq = new RandomizedQueue<>();
        while (!StdIn.isEmpty()) {
            String cmd = StdIn.readString();
            if (cmd.equals("enqueue")) rq.enqueue(StdIn.readString());
            else if (cmd.equals("dequeue")) StdOut.println(rq.dequeue());
            else if (cmd.equals("sample")) StdOut.println(rq.sample());
            else if (cmd.equals("size")) StdOut.println(rq.size());
        }
    }
}
