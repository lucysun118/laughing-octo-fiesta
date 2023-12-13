def scale_values(value):
    # Define the original range
    original_min = -7000
    original_max = 7000
    
    # Define the target range
    target_min = 1
    target_max = 10
    
    # Calculate the scaling factor
    scale_factor = (target_max - target_min) / (original_max - original_min)
    
    # Scale the value
    scaled_value = target_min + (value - original_min) * scale_factor
    
    # Ensure the scaled value is within the target range
    scaled_value = max(min(scaled_value, target_max), target_min)
    
    return scaled_value

# Example usage:
values_to_scale = range(-7000, 7001, 200)
scaled_values = [scale_values(value) for value in values_to_scale]

for value, scaled_value in zip(values_to_scale, scaled_values):
    print('{:>6.0f} --> {:>6.1f}'.format(value, scaled_value)) 