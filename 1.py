import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def main():
    img = cv.imread("al20884_CSAY-1.0_31-01-2025_193.JPG")
    if img is None:
        print("Image not found or unable to load.")
        return

    img = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    k = np.ones((11, 11), np.float32) / 2
    print(k)

    op = cv.filter2D(img, -1, k)

    plt.subplot(1, 2, 1)
    plt.imshow(img, cmap='gray')
    plt.title("Original Image")

    plt.subplot(1, 2, 2)
    plt.imshow(op, cmap='gray')
    plt.title("Filtered Image")

    plt.show()

if __name__ == "__main__":
    main()
