import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import Delaunay

# Generating random points for demonstration
np.random.seed(42)
points = np.random.rand(20, 2)  # Generating 10 random points in 2D space

# Creating the initial plot with points
plt.figure(figsize=(27, 9))

# Plotting the initial points
plt.subplot(131)
plt.plot(points[:, 0], points[:, 1], 'o', markersize=8)
plt.title('Step 1: Initial Points')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.axis('equal')
plt.grid(True)

# Step 2: Point Insertion and visualizing each step
for i in range(3, len(points) + 1):
    plt.subplot(132)
    plt.plot(points[:i, 0], points[:i, 1], 'o', markersize=8)
    
    # Creating Delaunay triangulation for the current set of points
    tri = Delaunay(points[:i])
    
    for simp in tri.simplices:
        plt.plot(points[simp, 0], points[simp, 1], 'k-')
    
    plt.title('Step 2: Point Insertion')
    plt.xlabel('X-axis')
    plt.ylabel('Y-axis')
    plt.axis('equal')
    plt.grid(True)
    plt.pause(1)  # Pause to visualize each point insertion

# Step 3: Final Delaunay triangulation with convex hull
plt.subplot(133)
plt.plot(points[:, 0], points[:, 1], 'o', markersize=8)
tri = Delaunay(points)
for simp in tri.simplices:
    plt.plot(points[simp, 0], points[simp, 1], 'k-')
    
# Plotting the convex hull
for edge in tri.convex_hull:
    plt.plot(points[edge, 0], points[edge, 1], 'r--')
    
plt.title('Step 3: Final Delaunay Triangulation with Convex Hull')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.axis('equal')
plt.grid(True)

plt.tight_layout()
plt.show()
