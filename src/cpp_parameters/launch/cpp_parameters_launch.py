from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'background_r': 190,
                'background_g': 70,
                'background_b': 190}
            ]
        )
    ])
